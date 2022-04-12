const bodyParser = require ("body-parser");
const express = require('express');
const bcrypt = require('bcrypt');
var jwt = require('jsonwebtoken');
var mysql = require('mysql');
const secret = process.env.SECRET;
const path = require("path");
const app = express();
const router = global.router;
let validateRequest = require ("../../middleware/auth").validateRequest;
let Validjwt = require ("../../middleware/auth").Validjwt;
let connection = require ("../../config/db").connection;

app.use(bodyParser.json());

router.post('/login', function (req, res) {
    required: ['email', 'password'];
    const rounds = 10;
    const values = [
        req.body.email,
        bcrypt.hash(req.body.password, 10, (err, hash) => {
            if(err) {
                console.error(err)
                return
            }
            console.log(hash)
        })
    ];
    const sql = "SELECT id FROM user WHERE email=? AND password=?";
    connection.query(sql, [values[0], values[1]], function (err, result) {
        if (err) {
            res.status(500).send("internal serveur error");
            return;
        }
        console.log(values[1]);
        if (result[0] == undefined) {
            res.send(301,"Invalid Credentials");
            return;
        }
        else{
            let sql = "SELECT * FROM user WHERE id=?";
            let token = jwt.sign({ id: sql }, secret, {
                expiresIn: 86400 // expires in 24 hours
            });
            res.status(200).send({ auth: true, token: token });
            res.redirect(301,"http://localhost:5432/todo");
        }
    });
});

function login(param) {
}

login( function (req, res) {
    res.send("login");
});

router.get('/register', function (req, res) {
    res.sendFile(path.join(__dirname, '../../',  'register.html'));

});

router.post('/register', function (req, res) {
    if (req.body === ''){
        res.status(404).send('Bad Request');
    }else {
        const sql = "SELECT * FROM user WHERE email=?";
        connection.query(sql, [req.body.email], function (err, result) {
            if (err) {
                res.status(500).send("internal serveur error");
                return;
            }
            if (result[0] == undefined) {
                const sql = "INSERT INTO user (email, password, name, firstname) VALUES (?, ?, ?, ?)";
                bcrypt.hash(req.body.password, 10, (err, hash) => {
                    if(err) {
                        console.error(err)
                        return
                    }
                    console.log(req.body.email, hash, req.body.name, req.body.firstname);
                    connection.query(sql, [req.body.email, hash, req.body.name, req.body.firstname], function (err, result) {
                        if (err) {
                            console.error(err);
                            res.status(500).send("internal serveur error");
                            return;
                        }
                        let sql = "SELECT id FROM user WHERE email=?";
                        connection.query(sql, [req.body.email], function (err, result) {
                            if (err) {
                                console.error(err);
                                res.status(500).send("internal serveur error");
                                return;
                            }
                            let token = jwt.sign({ id: sql }, secret, {
                                expiresIn: 86400 // expires in 24 hours
                            });
                            res.status(200).send({ auth: true, token: token });
                            res.redirect(301,"http://localhost:5432/todo");
                        });
                    });
                });
            } else {
                res.send(301, "account already exists");
            }   
        });
    }
});
module.exports = router;
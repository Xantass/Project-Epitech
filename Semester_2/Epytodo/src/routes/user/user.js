const express = require('express');
const { connection } = require('../../config/db');
const app = express();
const router = global.router;

router.get('/user', function (req, res) {
    res.send("user");
    var sql = "SELECT * FROM user";
    connection.query(sql, function (err, result) {
        if (err) {
            res.status(500).send("internal serveur error");
            return;
        }
        res.send(result);
    });
});

router.get('/user/todos', function (req, res) {
    res.send("user todos");
    const value = [
        req.body.id
    ];
    var sql = "SELECT * FROM todo WHERE id=?";
    connection.query(sql, [value], function (err, result) {
        if (err) {
            res.status(500).send("internal serveur error");
            return;
        }
        res.send(result);
    });
});

router.get('/user/:id', function (req, res) {
    res.send("id");
    const value = [
        req.body.id
    ];
    var sql = "SELECT * FROM user WHERE id=?";
    connection.query(sql, [value], function (err, result) {
        if (err) {
            res.status(500).send("internal serveur error");
            return;
        }
        res.send(result);
    });
});

router.get('/user/:email', function (req, res) {
    res.send("email");
    const value = [
        req.body.email
    ];
    var sql = "SELECT * FROM user WHERE email=?";
    connection.query(sql, [value], function (err, result) {
        if (err) {
            res.status(500).send("internal serveur error");
            return;
        }
        res.send(result);
    })
});

module.exports = router;
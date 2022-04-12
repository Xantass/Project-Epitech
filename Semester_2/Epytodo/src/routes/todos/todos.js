const express = require('express');
const path = require("path");
const app = express();
const router = global.router;

router.get('/todo', function (req, res) {
    res.sendFile(path.join(__dirname, '../../',  'todo.html'));
    const sql = "SELECT * FROM todo"
    connection.query(sql, function (err, result) {
        if (err) {
            res.status(500).send("internal serveur error");
            return;
        }
        res.send(result);
    });
});
router.get('/todo/:id', function (req, res) {
    res.send("user");
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

module.exports = router;
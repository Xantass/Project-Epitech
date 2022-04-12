const express = require('express');
const app = express();
const router = global.router;


router.post('/todo', function (req, res) {
    res.send("create todo");
    const values = [
        req.body.title,
        req.body.description,
        req.body.status,
        req.body.due_time
    ];
    const sql = "INSERT INTO todo (title, description, status, due_time) VALUES (?)";
    connection.query(sql, [values], function (err, result) {
        if (err) {
            res.status(500).send("internal serveur error");
            return;
        }
        console.log(result);
    });
});

router.put('/todo/:id', function (req, res) {
    res.send("todo");
    const value = [
        req.body.id,
        req.body.title,
        req.body.description,
        req.body.status
    ];
    var sql = "UPDATE user SET title=?, description=?, status=? WHERE id=?";
    connection.query(sql, [value[1], value[2], value[3], value[0]], function (err, result) {
        if (err) {
            res.status(500).send("internal serveur error");
            return;
        }
        res.send(result);
    });
});

router.delete('/todo/:id', function (req, res) {
    res.send("todo");
});
module.exports = router;
const express = require('express');
const app = express();
const router = global.router;

app.put('/user/:id', function (req, res) {
    res.send("user");
    const value = [
        req.body.id,
        req.body.email,
        req.body.password,
        req.body.firstname,
        req.body.name
    ];
    var sql = "UPDATE user SET email=?, password=?, firstname=?, name=? WHERE id=?";
    connection.query(sql, [value[1], value[2], value[3], value[4]], function (err, result) {
        if (err) {
            res.status(500).send("internal serveur error");
            return;
        }
        res.send(result);
    });
});

app.delete('/user/:id', function (req, res) {
    res.send("user");
    const value = [
        req.body.id
    ];
    var sql = "DELETE FROM user WHERE id=?";
    connection.query(sql, [value], function (err, result) {
        if (err) {
            res.status(500).send("internal serveur error");
            return;
        }
        res.send("succesfully  deleted  record  number: ", value[0]);
    });
});
module.exports = router;
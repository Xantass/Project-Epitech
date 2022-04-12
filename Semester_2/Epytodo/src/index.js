const express = require ("express");
const app = express();
require('dotenv').config();
const port = process.env.PORT;
const router = (global.router = (express.Router()));
const bodyParser = require('body-parser');
let user = require('./routes/user/user');
let todos = require('./routes/todos/todos');
let auth = require('./routes/auth/auth');
const path = require("path");
app.use(bodyParser.urlencoded({ extended: true }));

app.use('/user', user);
app.use('/todos', todos);
app.use('/auth', auth);
app.use(router);


app.get('/', function (req, res) {
    res.sendFile(path.join(__dirname + '/index.html'));
});

app.listen(port, () => {
    console.log(`listening at http://localhost:${port}`);
});
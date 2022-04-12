const mysql = require('mysql');
require('dotenv').config()

const host = process.env.MYSQL_HOST;
const user = process.env.MYSQL_USER;
const password = process.env.MYSQL_ROOT_PASSWORD;
const database = process.env.MYSQL_DATABASE;

const connection = mysql.createConnection({
    host: host,
    user: user,
    password: password,
    database: database
});

connection.connect((err) => {
    if (err) throw err;
    console.log('Connected!');
});
module.exports = {
    connection: connection
}
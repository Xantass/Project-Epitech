const bodyParser = require ("body-parser");
const express = require('express');
const app = express();
const router = global.router;
const secret = process.env["SECRET "];
const jwt = require('jsonwebtoken');

function validateRequest(options) {
    return (req, res, next) => {
        const { body } = req;
        const { required } = options;
        const errors = {};

        if (required && required.length) {
            required.forEach(key => {
                const value = `${body[key]}`;

                if (value === {}) {
                    errors[key] = 'This field is required';
                }
            });
        }
            next();
    }
}

function Validejwt(req, res, next) {
    try {
        const token = req.headers.authorization.split(' ')[1];
        const decodedToken = jwt.verify(token, secret);
        const userId = decodedToken.userId;
        if (req.body.userId && req.body.userId !== userId) {
            throw 'Invalid user ID';
        } else {
            next();
        }
    } catch {
        res.status(401).json({
            error: new Error('Invalid request')
        });
    }
};

function verifyToken(req, res, next) {
    let token = req.headers['x-access-token'];
    if (!token)
        return res.status(403).send({ auth: false, message: 'No token provided.' });

    jwt.verify(token, config.secret, function(err, decoded) {
        if (err)
            return res.status(500).send({ auth: false, message: 'Failed to authenticate token.' });
        req.userId = decoded.id;
        next();
    });
}

module.exports = {
    verifyToken : verifyToken,
    Validejwt : Validejwt,
    validateRequest : validateRequest
}
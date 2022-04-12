CREATE DATABASE IF NOT EXISTS epytodo;

USE epytodo
CREATE TABLE IF NOT EXISTS user
(
    id smallint unsigned not null auto_increment,
    email text not null,
    password text not null,
    name text not null,
    firstname text not null,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS todo
(
    id smallint unsigned not null auto_increment,
    title text not null,
    description text not null,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    due_time DATETIME not null,
    status ENUM('not started', 'todo', 'in progress', 'done'),
    user_id smallint unsigned,
    PRIMARY KEY (id),
    FOREIGN KEY (user_id) REFERENCES user(id)
);
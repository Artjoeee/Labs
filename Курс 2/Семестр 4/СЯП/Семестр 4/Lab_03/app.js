"use strict";
// 1
class BaseUser {
    getRole() {
        return this.role;
    }
    getPermissions() {
        return this.permissions;
    }
}
class Guest extends BaseUser {
    constructor(id, name) {
        super();
        this.id = id;
        this.name = name;
        this.role = "Гость";
        this.permissions = ["Просмотр контента"];
    }
}
class User extends BaseUser {
    constructor(id, name) {
        super();
        this.id = id;
        this.name = name;
        this.role = "Пользователь";
        this.permissions = ["Просмотр контента", "Добавление комментариев"];
    }
}
class Admin extends BaseUser {
    constructor(id, name) {
        super();
        this.id = id;
        this.name = name;
        this.role = "Пользователь";
        this.permissions = [
            "Просмотр контента", "Добавление комментариев",
            "Удаление комментариев", "Управление пользователями"
        ];
    }
}
const guest = new Guest(1, "Аноним");
console.log(guest.getPermissions());
const admin = new Admin(2, "Мария");
console.log(admin.getPermissions());
class HTMLReport {
    constructor(reportTitle, reportContent) {
        this.title = reportTitle;
        this.content = reportContent;
    }
    generate() {
        return `<h1>${this.title}</h1><p>${this.content}</p>`;
    }
}
class JSONReport {
    constructor(reportTitle, reportContent) {
        this.title = reportTitle;
        this.content = reportContent;
    }
    generate() {
        return JSON.stringify(this);
    }
}
const report1 = new HTMLReport("Отчёт1", "Содержание отчета");
console.log(report1.generate());
const report2 = new JSONReport("Отчёт2", "Содержание отчета");
console.log(report2.generate());
class CacheGeneric {
    constructor() {
        this.start = new Date().getTime();
        this.map = new Map();
    }
    add(key, value, ttl) {
        this.map.set(key, { value, ttl });
    }
    get(key) {
        let end = new Date().getTime();
        let time = end - this.start;
        let element = this.map.get(key);
        if (time <= element.ttl) {
            return element.value;
        }
        else {
            return null;
        }
    }
    clearExpired() {
        for (let key of this.map.keys()) {
            if (this.get(key) == null) {
                this.map.delete(key);
            }
        }
    }
}
const cache = new CacheGeneric();
cache.add("price", 100, 5000);
console.log(cache.get("price"));
setTimeout(() => console.log(cache.get("price")), 6000);
// 4
function createInstance(cls, ...args) {
    let object = new cls(...args);
    return object;
}
class Product {
    constructor(name, price) {
        this.name = name;
        this.price = price;
    }
}
const p = createInstance(Product, "Телефон", 50000);
console.log(p);
// 5
var LogLevel;
(function (LogLevel) {
    LogLevel["INFO"] = "INFO";
    LogLevel["WARNING"] = "WARNING";
    LogLevel["ERROR"] = "ERROR";
})(LogLevel || (LogLevel = {}));
;
function logEvent(event) {
    console.log(`[${event[0].toISOString()}] [${event[1]}]: ${event[2]}`);
}
logEvent([new Date(), LogLevel.INFO, "Система запущена"]);
// 6
var HttpStatus;
(function (HttpStatus) {
    HttpStatus[HttpStatus["OK"] = 200] = "OK";
    HttpStatus[HttpStatus["NOT_FOUND"] = 404] = "NOT_FOUND";
    HttpStatus[HttpStatus["BAD_REQUEST"] = 400] = "BAD_REQUEST";
    HttpStatus[HttpStatus["INTERNAL_SERVER_ERROR"] = 500] = "INTERNAL_SERVER_ERROR";
})(HttpStatus || (HttpStatus = {}));
;
function success(data) {
    return [HttpStatus.OK, data];
}
function error(message, status) {
    return [status, null, message];
}
const res1 = success({ user: "Андрей" });
console.log(res1);
const res2 = error("Не найдено", HttpStatus.NOT_FOUND);
console.log(res2);

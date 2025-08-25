"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
// 2
let myPromise = new Promise((resolve, reject) => {
    setTimeout(() => resolve(new Date().getTime() % 100), 3000);
});
myPromise.then(result => console.log(result));
// 3
function getPromice(delay) {
    return new Promise((resolve, reject) => {
        setTimeout(() => resolve(new Date().getTime() % 100), delay);
    });
}
Promise.all([
    getPromice(4000),
    getPromice(3000),
    getPromice(2000)
]).then(console.log);
// 4
let pr = new Promise((resolve, reject) => {
    setTimeout(() => reject('ku'), 5000);
});
pr
    .then(() => console.log(1))
    .catch(() => console.log(2))
    .catch(() => console.log(3))
    .then(() => console.log(4))
    .then(() => console.log(5));
// 5
let myNewPromise = new Promise((resolve, reject) => {
    setTimeout(() => resolve(21), 6000);
});
myNewPromise.then((result) => {
    console.log(result);
    return result * 2;
}).then((result) => {
    console.log(result);
});
// 6
function getChain() {
    return __awaiter(this, void 0, void 0, function* () {
        let myNewPromise = new Promise((resolve, reject) => {
            setTimeout(() => resolve(21), 7000);
        });
        let result = yield myNewPromise;
        console.log(result);
        result *= 2;
        console.log(result);
    });
}
getChain();
// 7
let promise1 = new Promise((resolve, reject) => {
    setTimeout(() => resolve('Resolved promise - 1'), 7500);
});
promise1
    .then((result) => {
    console.log("Resolved promise - 2");
    return "OK";
})
    .then((result) => {
    console.log(result);
});
// 8
let promise2 = new Promise((resolve, reject) => {
    setTimeout(() => resolve('Resolved promise - 1'), 8000);
});
promise2
    .then((result) => {
    console.log(result);
    return "OK";
})
    .then((result1) => {
    console.log(result1);
});
// 9
let promise3 = new Promise((resolve, reject) => {
    setTimeout(() => resolve('Resolve promise - 1'), 8500);
});
promise3
    .then((result) => {
    console.log(result);
    return result;
})
    .then((result1) => {
    console.log('Resolved promise - 2');
});
// 10
let promise4 = new Promise((resolve, reject) => {
    setTimeout(() => resolve('Resolved promise - 1'), 9000);
});
promise4
    .then((result) => {
    console.log(result);
    return result;
})
    .then((result1) => {
    console.log(result1);
});
// 11
let promise5 = new Promise((resolve, reject) => {
    setTimeout(() => resolve('Resolved promise - 1'), 9500);
});
promise5
    .then((result) => {
    console.log(result);
})
    .then((result1) => {
    console.log(result1);
});

"use strict";
// 1
function createPhoneNumber(arr) {
    let phoneNumber = "";
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] > 9) {
            return "Неверный номер";
        }
        if (i == 0) {
            phoneNumber += "(";
        }
        if (i == 3) {
            phoneNumber += ") ";
        }
        if (i == 6) {
            phoneNumber += "-";
        }
        phoneNumber += arr[i];
    }
    return phoneNumber;
}
let newPhoneNumber = createPhoneNumber([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);
console.log(newPhoneNumber);
// 2
class Challenge {
    static solution(number) {
        let sum = 0;
        for (let i = 0; i < number; i++) {
            if (number < 0) {
                return 0;
            }
            if (i % 3 == 0 || i % 5 == 0) {
                sum += i;
            }
        }
        return sum;
    }
}
let sumOfNumbers = Challenge.solution(10);
console.log(sumOfNumbers);
// 3
function arrayShift(steps, nums) {
    if (steps < 0) {
        return nums;
    }
    for (let i = 0; i < steps; i++) {
        let lastElement = nums[nums.length - 1];
        nums.pop();
        nums.unshift(lastElement);
    }
    return nums;
}
let newArray = arrayShift(13, [1, 2, 3, 4, 5, 6, 7]);
console.log(newArray);
// 4
function getMedian(nums1, nums2) {
    let sortArray = nums1.concat(nums2).sort(function (a, b) { return a - b; });
    let median = 0;
    let len = sortArray.length;
    if (sortArray.length % 2 == 0) {
        median = (sortArray[(len / 2) - 1] + sortArray[len / 2]) / 2;
    }
    if (sortArray.length % 2 != 0) {
        median = sortArray[(len - 1) / 2];
    }
    return median;
}
let arrayMedian = getMedian([1, 3], [2, 4, 5, 6]);
console.log(arrayMedian);

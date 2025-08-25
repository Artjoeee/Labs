// 1
function createPhoneNumber(arr: number[]): string {
    let phoneNumber: string = "";

    for (let i: number = 0; i < arr.length; i++) {
        if (arr[i] > 9) {
            return "Неверный номер";
        }

        if (i == 0) {
            phoneNumber += "(";
        }

        if (i == 3) {
           phoneNumber +=") ";
        }

        if (i == 6) {
            phoneNumber += "-";
        }

        phoneNumber += arr[i];
    }

    return phoneNumber;
}

let newPhoneNumber: string = createPhoneNumber([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);
console.log(newPhoneNumber);

// 2
class Challenge {
    static solution(number: number): number {
        let sum: number = 0;

        for (let i: number = 0; i < number; i++) {
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
function arrayShift(steps: number, nums: number[]): number[] {
    if (steps < 0) {
        return nums;
    }
    
    for (let i: number = 0; i < steps; i++) {
        let lastElement: number = nums[nums.length - 1];
        nums.pop();
        nums.unshift(lastElement);
    }

    return nums;
}

let newArray: number[] = arrayShift(13, [1, 2, 3, 4, 5, 6, 7]);
console.log(newArray);

// 4
function getMedian(nums1: number[], nums2: number[]): number {
    let sortArray = nums1.concat(nums2).sort(function (a, b) { return a - b; });

    let median: number = 0;
    let len: number = sortArray.length;
    
    if (sortArray.length % 2 == 0) {
        median = (sortArray[(len / 2) - 1] + sortArray[len / 2]) / 2
    }

    if (sortArray.length % 2 != 0) {
        median = sortArray[(len - 1) / 2];
    }

    return median;
}

let arrayMedian: number = getMedian([1, 3], [2, 4, 5, 6]);
console.log(arrayMedian);
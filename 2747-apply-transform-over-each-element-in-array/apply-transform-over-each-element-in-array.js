/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let returnedArray = new Array(arr.length);
    for (let i = 0; i < arr.length; i++)
        returnedArray[i] = fn(arr[i],i);
    return returnedArray;
};
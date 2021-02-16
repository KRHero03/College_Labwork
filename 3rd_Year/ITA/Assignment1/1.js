const prompt = require('prompt-sync')();


try {
    const inputString = prompt('Please enter 3 numbers separated by spaces: ')

    const arr = inputString.split(' ').map(x => parseInt(x))
    if(arr.length!=3) throw 'Please enter 3 numbers.'
    const maxElem = Math.max(...arr)
    console.log('The Maximum of given numbers is ' + maxElem + '!')

} catch (e) {

    console.log('Program exited due to unforeseen error!')
    console.log('Error: '+e)
}

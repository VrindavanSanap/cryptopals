function hexToBinary(hexString) {
    let binaryString = "";
    for (let i = 0; i < hexString.length; i += 2) {
        let byte = parseInt(hexString.slice(i, i + 2), 16)
        let byte_string = byte.toString(2)
        byte_string = (8 - byte_string.length) * "0" + byte_string
        binaryString += byte_string
        console.log(`${byte}--> ${byte_string}`)
    }
    return binaryString
}
console.log("0"*2)
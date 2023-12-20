function hexToBinary(hexString) { 
    let binaryString = "";
    for (let i = 0; i < hexString.length; i += 2) { 
        let byte = parseInt(hexString.slice(i, i + 2), 16)
        let byte_string = byte.toString(2)
        byte_string = "0".repeat(8 - byte_string.length)  + byte_string  
        binaryString += byte_string
       
    }
    return binaryString
}

function hexToBase64(hexString) { 
    const base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    let binaryString = hexToBinary(hexString)

    let base64String = ""
    while (binaryString.length % 6 != 0) { 
        binaryString += "00"
    }
    console.log(`binaryString: ${binaryString}`)
    for (let i = 0; i < binaryString.length; i += 6) {
        let index = parseInt(binaryString.slice(i,i+6), 2)
        base64String += base64Chars[index]
    }
    while (base64String.length % 4 != 0) {
        base64String += "="
    }
    return base64String
}
const hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
console.log(`hexString: ${hexString}`)
const base64String = hexToBase64(hexString)
console.log(`base64String: ${base64String }`)
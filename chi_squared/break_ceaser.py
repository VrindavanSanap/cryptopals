#!/usr/bin/python3

import numpy as np
expected_prob = np.array([0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 
        0.06094, 0.06966, 0.00153, 0.00772,0.04025, 0.02406, 0.06749, 0.07507, 
        0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978,0.02360, 
      0.00150, 0.01974, 0.00074])
chars = "abcdefghijklmnopqrstuvwxyz"
assert len(chars) == 26
stoi = { ch:i for i,ch in enumerate(chars) }
itos = { i:ch for i,ch in enumerate(chars) }

def chi_squared(expected, observed):
  expected = np.array(expected)
  observed = np.array(observed)

  return ((observed - expected)**2/ expected).sum()

def keep_only_alpha(message):
  
  result = ""
  message = message.lower()
  for c in message:
    if c.isalpha():
      result += c
  return result 

def ceaser_cipher(message, n):
  result = ''
  message = keep_only_alpha(message)
  for c in message:
    cr = itos[(stoi[c] + n) % 26]
    result += cr 
  return result

def word_freq(string):  
  """
  given a string return frequencies as a list 
  """
  frequencies = np.zeros(26) 
  for char in string:
    if char.isalpha():
      char = char.lower()
      index = ord(char) - ord('a')
      frequencies[index] += 1
     
  return frequencies

def sentence_chi_squared(sentence):
  length = len(sentence)
  expected_freq = expected_prob * length 
  chi_squared_score = chi_squared(expected_freq, word_freq(sentence)) 
  return chi_squared_score
encrypted_message = "aoljhlzhyjpwolypzvulvmaollhysplzaruvduhukzptwslzajpwoly\
zpapzhafwlvmzbizapabapvujpwolypudopjolhjoslaalypuaolwsh\
pualeapzzopmalkhjlyahpuubtilyvmwshjlzkvduaolhswohila"


print(sentence_chi_squared("hello world"))
exit(-1)
for i in range(1, 27):
  ciphered = ceaser_cipher(encrypted_message, i)
  score = sentence_chi_squared(ciphered)
  print(f"{i} {score:.2f} {ciphered}") 
  print("--")


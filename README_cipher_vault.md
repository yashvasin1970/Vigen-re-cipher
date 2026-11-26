# Cipher Vault

A terminal program written in C that encrypts and decrypts messages with the Vigenère cipher, a classic method that shifts each letter by the matching letter of a secret key word.

## Features

- Encrypt a message with a key word
- Decrypt a message with the same key word
- Keeps spaces, numbers, and punctuation unchanged
- Keeps the capitalisation of every letter
- Rejects keys that contain anything other than letters
- Accepts messages up to 299 characters

## Requirements

- A C compiler such as `gcc` or `clang`

## Building

```
gcc cipher_vault.c -o vault -Wall
```

## Running

```
./vault
```

On Windows, use `vault.exe` after compiling with MinGW or a similar compiler.

## Using the program

The menu offers three options:

```
1. Encrypt a message
2. Decrypt a message
3. Quit
```

For options 1 and 2, the program asks for:

1. **Message:** the text to encrypt or decrypt. Spaces are allowed.
2. **Key:** a word using letters only, such as `LEMON`. Upper and lower case both work.

The result is printed straight away.

## Example

| Step       | Text                |
|------------|---------------------|
| Message    | `Attack at dawn!`   |
| Key        | `LEMON`             |
| Encrypted  | `Lxfopv ef rnhr!`   |
| Decrypted  | `Attack at dawn!`   |

To decrypt, choose option 2 and enter the encrypted text with the same key.

## How it works

Each letter in the message is shifted forward in the alphabet by the position of the matching key letter. The key repeats as needed. Only letters advance the key, so spaces and punctuation do not use up a key letter. Decryption reverses each shift.

## Known limitations

- The cipher is easy to break with frequency analysis or a dictionary attack, so it is for learning, not for real security.
- Messages are limited to 299 characters.
- Keys can be up to 49 characters long.

## Project structure

```
cipher_vault.c   Source code
README.md        This file
```

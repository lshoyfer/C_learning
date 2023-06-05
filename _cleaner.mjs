/*
    Cleans excerpts from Apple Books which contain invisible
    unicode spaces, quotes, and a source at bottom, into just
    a more pure and convenient copy paste. Amen.
*/

import * as readline from 'node:readline/promises';
import { stdin as input, stdout as output } from 'node:process';
import * as fs from 'node:fs/promises';

const rl = readline.createInterface({ input, output });

try {
    await fs.writeFile('./_output.txt', '');
} catch (err) {
    console.log(err);
}

// cut excerpt and clean extra front spaces
let s = '';
let code = true;
let firstline = true;
for await (const line of rl) {
    if (line.includes("Excerpt From")) code = false;
    if (line.includes("This material may be protected by copyright.")) break;
    if (code) s += (firstline 
        ? ((firstline = false), line)
        : line.slice(5))
            + '\n'; /* honestly this is illegible I'ma start quitting 
                    ternary operator overuse, was fun while it lasted */
}

// remove unicode nonsense
s = s.replaceAll(/ /g, ' ');

// clean quotes
s = s.slice(1);
s = s.trim();
(s.at(-1) === '”') && (s = s.slice(0, -1));

// write
try {
    await fs.writeFile('./_output.txt', s);
} catch (err) {
    console.log(err);
}
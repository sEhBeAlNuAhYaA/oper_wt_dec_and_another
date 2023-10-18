# Operations with decimal, binary, octupal and hexadecimal numbers(and converting)


### Nuumerical Systems

    BINARY      : 0 1;

    DECIMAL     : 0 1 2 3 4 5 6 7 8 9;

    OCTUPAL     : 0 1 2 3 4 5 6 7;

    HEXADECIMAL : 0 1 2 3 4 5 6 7 8 9 - A  B  C  D  E  F;
                                      |10 11 12 13 14 15|

There is a programm, that alows you run som basic operations with decimal, binary octuple and hexadecimal numbers. 

At first to code this project, you need to understand how work and happening those operations. I explain that by using decimal numbers.

#### Addition(decimal)
As you can see below, to add numbers, we need to add they in columns, but when the result is bigger than our numeration system we should add to next column as much as our result bigger than system, and leave in current column remainder of this calculation.

    Addition in columns   :  5  + 7 = 11;
    Comparing with system :  11 > 10;
    Add to next column    :  12 / 10 = 1;
    Remainder             :  12 - 10 = 2;

<center>

      19        15        16
    + 30      + 27      + 35
    -----     -----     -----
      49        42        51

</center>

#### Subtraction(decimal)

Subtraction works like addition but, when our column-result is smaller then null, we should take in the next column one, and add to current column our numerical system and make subtraction again.

    Subtraction in columns :   5  - 7 = -2;
    Comparing with null    :   -2 < 0
    Next column            :   -1
    Current column         :   5  - 7 = -2 (+ 10) = 8;

<center>

      22        15        22
    - 11      +  7      - 13
    -----     -----     -----
      11         8         9

</center>

#### Multiplication(decimal)

To mult. the numbers we should mult. one number for each digit of another number, and add all of results.

### <center>OPERATIONS</center>

There is a table with variables i used for each operation;

<center>
<table frame = "box">
    <tr>
        <th>Addition</th>
        <th>Subtraction</th>
        <th>Multiplication</th>
    </tr>
    <tr>
        <th>variables: <br> transfer <br> answer </th>
        <th>variables: <br> transfer <br> answer <br> taken</th>
        <th>variables: <br> transfer <br> answer </th>
    </tr>
</table>
</center>

All my code consist of vectors of chars or integers numbers, i made this for simple working with input numbers.

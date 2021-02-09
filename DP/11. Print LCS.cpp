/*
This is a follow up to the LCS question. To print the longest substring we can use a trick to figure out how the table is being filled and then use that.
(This is not very logical but it works and this is how it is done by everyone.). If we observe the table, we can see that two thing happen while filling every block:
1. If the characters are equal we move diagonally right and add 1 to it.
2. If the characters are not equal we check the left and top block and take the max value and fill it inside here.

The table was filled logically and this is just an afterthought or an obseravation on the filled table. Please do not solve LCS like this.

Now if we can conclude this then its pretty easy to construct the LCS:
1. start from the last cell. If characters are equal append value to ans and move to upper left block.
2. if not equal, then move to the max block from the top or the left.

Finally revserse the string to get the correct string as answer.
*/

// Approach:
// check for presence of operator between matching parents, if no operator then bracket is redundant
// 
// if cur element is not ')' push it in stack
// else pop until '(' is found and check if operator comes or not 
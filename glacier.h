/**
 * @file glacier.h
 * @brief Definitions for password generating functions.
 * 
 * @author Stevie Alvarez
 */


#ifndef GLACIER_H
#define GLACIER_H


/**
 * Generates a randomized password of length l consisting of num 
 * integers, sp special characters, and (l - num - sp) alphabetic 
 * characters.
 * 
 * @param l desired length of password
 * @param num number of integers to be in password
 * @param sp number of special characters to be in password
 * @return a randomized password, within the provided parameters
 */
char * password(int l, int num, int sp);


#endif

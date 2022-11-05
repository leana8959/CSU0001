#pragma once

// Setup three points for a triangle.
// Success: return 1; Fail: return 0
int set_point_1( double x, double y);
int set_point_2( double x, double y);
int set_point_3( double x, double y);

// Check if the current setting is a valid triangle.
// Yes: return 1; No: return 0
int check( void );

// Return the perimeter of the triangle.
// For any errors , return < 0
double get_perimeter( void );

// Return the area of the triangle.
// For any errors , return < 0
double get_area( void );

// Get the degrees (0-360) of three angles
// For any errors , return < 0
double get_degree_1( void );
double get_degree_2( void );
double get_degree_3( void );

// The incircle (內 切 圓) of a triangle is the largest circle that can be contained in the triangle.
// Return the area of the incircle of the given triangle.
// For any errors , return < 0
double get_incircle_area( void );
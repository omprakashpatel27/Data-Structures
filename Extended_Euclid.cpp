// Extended Euclidian Algorithm ( EEA )
// Intgeral Solution of the equation : [ ax + by = c , where c is gcd(a,b) ] can be found using EEA 
// EEA gives one of the many integral value of x and y 

// ax + by = gcd(a,b) = g
// bx'+ (a%b)y' = gcd(b,a%b) = g
// (a%b)x'' + b%(a%b)y'' = gcd(a%b,b%(a%b)) = g
// ...
// ...
// gx''''' + 0y''''' = g
// this gives x''''' = 1 && y''''' can be any integral value

// Relation between next level equation and previous level:

// ax + by = gcd(a,b) = g --(1)
// bx'+ (a%b)y' = gcd(b,a%b) = g --(2)

// a % b can be written as a - [ a / b] * b
// bx' + ay' + ( [a / b] * b ) y' = g
// ay' + b(x' + [a / b] * y') = g --(3)

// From (1) & (3)
// x = y' and  y = x' + [a / b] * y'

// Code:
int gcd , x , y;
void Extended_Euclid(int a, int b){
    if(b == 0){
        // for different y' values at base case we can get 
        // different integral x and y values for the equation
        gcd = a; x = 1; y = 0;
        return;
    }
    Extended_Euclid(b, a%b);
    int temp = x; 
    x = y;
    y = temp - (a / b) * y;
}

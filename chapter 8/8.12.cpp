#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int A = 70;
void moveTortoise( int *const );
void moveHare( int *const );
void printCurrentPositions( const int *const, const int *const );

int main()
{
   int tortoise = 1;
   int hare = 1;
   int timer = 0;

   srand( time( 0 ) );

   cout << "ON YOUR MARK, GET SET\nBANG               !!!!"<< "\nAND THEY ARE OFF    !!!!\n";
   while ( tortoise != A && hare != A )
   {
      moveTortoise( &tortoise );
      moveHare( &hare );
      printCurrentPositions( &tortoise, &hare );
      timer++;
   }

   if ( tortoise >= hare )
      cout << "\nTORTOISE WINS!!! YAY!!!\n";
   else
      cout << "Hare wins. Yuch.\n";

   cout << "TIME ELAPSED = " << timer << " seconds" << endl;
}

void moveTortoise( int * const turtlePtr )
{
   int x = 1 + rand() % 10;

   if ( x >= 1 && x <= 5 )
      *turtlePtr += 3;
   else if ( x == 6 || x == 7 )
      *turtlePtr -= 6;
   else
      ++( *turtlePtr );

   if ( *turtlePtr < 1 )
      *turtlePtr = 1;
   else if ( *turtlePtr > A )
      *turtlePtr = A;
}

void moveHare( int * const rabbitPtr )
{
   int y = 1 + rand() % 10;
   if ( y == 3 || y == 4 )
      *rabbitPtr += 9;
   else if ( y == 5 )
      *rabbitPtr -= 12;
   else if ( y >= 6 && y <= 8 )
      ++( *rabbitPtr );
   else if ( y > 8 )
      *rabbitPtr -= 2;

   if ( *rabbitPtr < 1 )
      *rabbitPtr = 1;
   else if ( *rabbitPtr > A )
      *rabbitPtr = A;
}

void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr )
{
   if ( *bunnyPtr == *snapperPtr )
      cout << setw( *bunnyPtr ) << "OUCH!!!";
   else if ( *bunnyPtr < *snapperPtr )
      cout << setw( *bunnyPtr ) << "H"
         << setw( *snapperPtr - *bunnyPtr ) << "T";
   else
      cout << setw( *snapperPtr ) << "T"
         << setw( *bunnyPtr - *snapperPtr ) << "H";

   cout << "\n";
}

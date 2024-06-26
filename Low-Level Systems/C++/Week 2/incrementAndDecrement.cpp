// Increment and Decrement operator
int main(){
   int counter {10};
   int result {0};

   // Example 1 - simple increment
   cout << "Counter: " << counter << endl;

   counter = counter + 1;
   cout << "Counter: " << counter << endl;

   counter++;
   cout << "Counter: " << counter << endl;

   ++counter;
   cout << "Counter: " << counter << endl;
   cout << "*******************************" << endl;

   // Example 2 - pre-incremenmt
   counter = 10;
   result = 0;

   cout << "Counter: " << counter << endl;

   result = ++counter; // pre increment
   cout << "Counter: " << counter << endl;
   cout << "Result: " << result << endl;
   cout << "*******************************" << endl;


   // Example 3 - post-incremenmt
   counter = 10;
   result = 0;

   cout << "Counter: " << counter << endl;

   result = counter++; // post increment
   cout << "Counter: " << counter << endl;
   cout << "Result: " << result << endl;
   cout << "*******************************" << endl;

   // Example 4
   counter = 10;
   result = 0;

   cout << "Counter: " << counter << endl;

   result = ++counter + 10; // pre increment
   cout << "Counter: " << counter << endl;
   cout << "Result: " << result << endl;
   cout << "*******************************" << endl;

}

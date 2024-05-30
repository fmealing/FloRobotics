// Convert EUR to USD
int main(){
   const double usdPerEuro {1.19};
   double numEuro {0.0};
   double numDollar {0.0};

   cout << "Welcome to the EUR to USD converter" << endl;
   cout << "Enter the value in EUR: ";
   cin >> numEuro;

   numDollar = numEuro * usdPerEuro;
   cout << numEuro << " euros is equivalent to " << numDollar << " dollars" << endl;

   cout << endl;

   return 0;
}

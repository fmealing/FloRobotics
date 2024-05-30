// Arithmetic Operator
int main(){
   int num1 {200};
   int num2 {100};

   cout << num1 << " + " << num2 << " = " << num1+num2 << endl;

   int result {0};
   int result2 {0};
   int result3 {0};
   int result4 {0};
   int result5 {0};

   result = num1 + num2;
   cout << num1 << " + " << num2 << " = " << result << endl;

   result2 = num1 - num2;
   result3 = num1 * num2;
   result4 = num1 / num2;
   result5 = num1 % num2;

   cout << num1 << " - " << num2 << " = " << result2 << endl;
   cout << num1 << " * " << num2 << " = " << result3 << endl;
   cout << num1 << " / " << num2 << " = " << result4 << endl;
   cout << num1 << " % " << num2 << " = " << result5 << endl;

   return 0;
}

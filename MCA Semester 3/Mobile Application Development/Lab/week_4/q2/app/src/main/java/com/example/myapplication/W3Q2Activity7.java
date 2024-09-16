package com.example.myapplication;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class W3Q2Activity7 extends AppCompatActivity {

    private TextView resultTextView;
    private StringBuilder inputBuilder = new StringBuilder();
    private String operator = "";
    private double firstOperand = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_w3_q27);

        resultTextView = findViewById(R.id.resultTextView);
    }

    public void onNumberClick(View view) {
        Button button = (Button) view;
        inputBuilder.append(button.getText());
        resultTextView.setText(inputBuilder.toString());
    }

    public void onOperatorClick(View view) {
        Button button = (Button) view;
        if (inputBuilder.length() > 0) {
            firstOperand = Double.parseDouble(inputBuilder.toString());
            operator = button.getText().toString();
            inputBuilder.setLength(0); // Clear input for next number
        }
    }

    public void calculateResult(View view) {
        if (inputBuilder.length() > 0 && !operator.isEmpty()) {
            double secondOperand = Double.parseDouble(inputBuilder.toString());
            double result = 0;

            switch (operator) {
                case "+":
                    result = firstOperand + secondOperand;
                    break;
                case "-":
                    result = firstOperand - secondOperand;
                    break;
                case "*":
                    result = firstOperand * secondOperand;
                    break;
                case "/":
                    if (secondOperand != 0) {
                        result = firstOperand / secondOperand;
                    } else {
                        resultTextView.setText("Error"); // Handle division by zero
                        return;
                    }
                    break;
            }

            resultTextView.setText(String.valueOf(result));
            // Optionally, clear input after calculation
        }
    }

    public void clearInput(View view) {
        inputBuilder.setLength(0);
        resultTextView.setText("0");
        operator = "";
        firstOperand=0;
    }
    public void backToHome(View view) {
        // Replace with the package and main activity of your home app
        Intent intent = new Intent(W3Q2Activity7.this, MainActivity.class);
        startActivity(intent);
    }
}
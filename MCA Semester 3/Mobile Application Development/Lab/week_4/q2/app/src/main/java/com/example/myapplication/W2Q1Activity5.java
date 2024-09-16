package com.example.myapplication;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;


import androidx.appcompat.app.AppCompatActivity;

public class W2Q1Activity5 extends AppCompatActivity {

    ImageButton AddBtn;
    EditText n1;
    EditText n2;
    TextView res;
    int a,b;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_w2_q15);
        AddBtn = (ImageButton)  findViewById(R.id.button3);
        n1=(EditText) findViewById(R.id.editTextText1);
        n2=(EditText) findViewById(R.id.editTextText2);
        res = (TextView) findViewById(R.id.ResultText);

    }
    public static boolean isNumeric(String str) {
        try {
            Double.parseDouble(str);
            return true;
        } catch(NumberFormatException e){
            return false;
        }
    }
    public void add(View view) {

        if(n1.getText().length()==0||n2.getText().length()==0){
            Toast.makeText(this, "Empty fields! nothing to compute!", Toast.LENGTH_LONG).show();
            return;
        }
        if(isNumeric(String.valueOf(n1.getText()))&&isNumeric(String.valueOf(n2.getText()))){
            a = Integer.parseInt(String.valueOf(n1.getText()));
            b = Integer.parseInt(String.valueOf(n2.getText()));
            String result = "Result is " +Integer.toString(a+b);
            res.setText(result);
            Toast.makeText(this, result, Toast.LENGTH_LONG).show();

        }else{
            Toast.makeText(this, "String values arent allowed!!", Toast.LENGTH_LONG).show();
            reset(view);
        }
    }
    @SuppressLint("NewApi")
    public void reset(View view){
        n1.setText("");
        n2.setText("");
        res.setText("");
        n1.requestFocus();
    }
    public void backToHome(View view) {
        // Replace with the package and main activity of your home app
        Intent intent = new Intent(W2Q1Activity5.this, MainActivity.class);
        startActivity(intent);
    }
}
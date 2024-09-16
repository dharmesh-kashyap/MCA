package com.example.myapplication;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void launchApp(View view) {
        String buttonText = ((Button) view).getText().toString();
        Intent intent = null;

        switch (buttonText) {
            case "HelloWorld":
                intent = new Intent(MainActivity.this, W1Q1Activity2.class);
                break;
            case "Toast":
                intent = new Intent(MainActivity.this, W1Q2Activity3.class);
                break;
            case "Lifecycle":
                intent = new Intent(MainActivity.this, W1Q3Activity4.class);
                break;
            case "Add":
                intent = new Intent(MainActivity.this, W2Q1Activity5.class);
                break;
            case "Form":
                intent = new Intent(MainActivity.this, W3Q1Activity6.class);
                break;
            case "Calculator":
                intent = new Intent(MainActivity.this, W3Q2Activity7.class);
                break;
            default:
                return;
        }

        startActivity(intent);
    }
    public void exitApp(View view) {
        finish();
        System.exit(0);
    }
}

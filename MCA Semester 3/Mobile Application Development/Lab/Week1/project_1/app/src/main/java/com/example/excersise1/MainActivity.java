package com.example.excersise1;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;


public class MainActivity extends AppCompatActivity {
    Button b1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toast.makeText(this, "Welcome to the app", Toast.LENGTH_SHORT).show();
        b1 = (Button) findViewById(R.id.button01);

        b1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(MainActivity.this, "Hello  \uD83D\uDE04\uD83D\uDE04", Toast.LENGTH_SHORT).show();
            }
        });
    }
}


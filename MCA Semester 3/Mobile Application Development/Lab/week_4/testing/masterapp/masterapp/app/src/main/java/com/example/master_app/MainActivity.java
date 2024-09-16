package com.example.master_app;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button buttonProject1 = findViewById(R.id.button_project1);
        Button buttonProject2 = findViewById(R.id.button_project2);
        Button buttonProject3 = findViewById(R.id.button_project3);
        Button buttonProject4 = findViewById(R.id.button_project4);

        buttonProject1.setOnClickListener(v -> startActivity(new Intent(MainActivity.this, Project1.class)));
        buttonProject2.setOnClickListener(v -> startActivity(new Intent(MainActivity.this, Project2.class)));
        //buttonProject3.setOnClickListener(v -> startActivity(new Intent(MainActivity.this, Project3Activity.class)));
        //buttonProject4.setOnClickListener(v -> startActivity(new Intent(MainActivity.this, Project4Activity.class)));
    }
}

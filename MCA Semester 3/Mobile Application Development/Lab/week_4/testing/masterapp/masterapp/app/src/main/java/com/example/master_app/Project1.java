package com.example.master_app;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

public class Project1 extends AppCompatActivity {
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_project1);

        // Initialize the button
        btn = findViewById(R.id.but);  // Find the button with ID 'but'
        Toast.makeText(this, "Hello", Toast.LENGTH_SHORT).show();

        // Set up a click listener for the button
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(Project1.this, "WELCOME FROM TOAST MESSAGE", Toast.LENGTH_LONG).show();
            }
        });

        // Set up the Toolbar
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        // Enable the back arrow on the toolbar
        if (getSupportActionBar() != null) {
            getSupportActionBar().setDisplayHomeAsUpEnabled(true);
            getSupportActionBar().setDisplayShowHomeEnabled(true);
        }

        // Set a click listener on the navigation icon (back arrow)
        toolbar.setNavigationOnClickListener(v -> onBackPressed());
    }
}

package com.example.myapplication;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class W3Q1Activity6 extends AppCompatActivity {
    EditText name;
    RadioGroup rg;
    RadioButton male;
    RadioButton female;
    CheckBox sports;CheckBox art;CheckBox sw;
    Button clickme;
    TextView eyd;
    TextView gender;
    TextView likes;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_w3_q16);
        name = (EditText) findViewById(R.id.editTextText1);
        rg = (RadioGroup) findViewById(R.id.rg);
        male = (RadioButton) findViewById(R.id.rb1);
        female = (RadioButton) findViewById(R.id.rb2);
        sports = (CheckBox) findViewById(R.id.sports);
        art = (CheckBox) findViewById(R.id.art);
        sw = (CheckBox) findViewById(R.id.sw);
        clickme = (Button) findViewById(R.id.button);
        eyd = ( TextView) findViewById(R.id.eyd);
        gender = ( TextView) findViewById(R.id.gender);
        likes = ( TextView) findViewById(R.id.likes);
    }
    public void onButtonClick(View view) {
        String userName = name.getText().toString().trim();
        String selectedGender = null;
        String selectedLikes = "";

        // Validation for the name field
        if (userName.isEmpty()) {
            Toast.makeText(W3Q1Activity6.this, "Name field cannot be empty", Toast.LENGTH_SHORT).show();
            return;
        }

        // Get selected gender
        int selectedGenderId = rg.getCheckedRadioButtonId();
        if (selectedGenderId == R.id.rb1) {
            selectedGender = "male";
        } else if (selectedGenderId == R.id.rb2) {
            selectedGender = "female";
        } else {
            Toast.makeText(W3Q1Activity6.this, "Please select a gender", Toast.LENGTH_SHORT).show();
            return;
        }

        // Get selected likes
        if (sports.isChecked()) {
            selectedLikes += "sports, ";
        }
        if (art.isChecked()) {
            selectedLikes += "art, ";
        }
        if (sw.isChecked()) {
            selectedLikes += "social work, ";
        }

        // Remove the trailing comma and space, if any
        if (!selectedLikes.isEmpty()) {
            selectedLikes = selectedLikes.substring(0, selectedLikes.length() - 2);
        } else {
            selectedLikes = "nothing!";
        }

        // Update the TextViews
        eyd.setText("Hello " + userName);
        gender.setText(userName + " is a " + selectedGender);
        likes.setText(userName + " likes " + selectedLikes);
        InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(view.getWindowToken(), 0);
    }
    public void onResetClick(View view) {
        // Reset all fields
        name.setText("");
        rg.clearCheck();
        sports.setChecked(false);
        art.setChecked(false);
        sw.setChecked(false);

        // Reset the TextViews
        eyd.setText("Enter Your Details");
        gender.setText("");
        likes.setText("");

        // Optionally, you can also hide the keyboard here

    }
    public void backToHome(View view) {
        // Replace with the package and main activity of your home app
        Intent intent = new Intent(W3Q1Activity6.this, MainActivity.class);
        startActivity(intent);
    }
}
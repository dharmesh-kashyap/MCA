package com.example.spinner_customtoast;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

     Spinner bankSpinner;
     ImageView bankLogo;

     String[] bankNames = {"Bank A", "Bank B", "Bank C"};
     int[] bankLogos = {R.drawable.bank_a_logo, R.drawable.bank_b_logo, R.drawable.bank_c_logo};
     String[] ifscCodes = {"IFSC0001", "IFSC0002", "IFSC0003"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        bankSpinner = findViewById(R.id.bankSpinner);
        bankLogo = findViewById(R.id.bankLogo);

        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, bankNames);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        bankSpinner.setAdapter(adapter);

        bankSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                displayBankDetails(position);
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
                // Do nothing
            }
        });
    }

    private void displayBankDetails(int position) {
        bankLogo.setImageResource(bankLogos[position]);

        // Create a custom toast
        LayoutInflater inflater = getLayoutInflater();
        View layout = inflater.inflate(R.layout.custom_toast, (ViewGroup) findViewById(R.id.custom_toast_container));

        @SuppressLint({"MissingInflatedId", "LocalSuppress"}) ImageView logo = layout.findViewById(R.id.toast_image);
        logo.setImageResource(bankLogos[position]);

        @SuppressLint({"MissingInflatedId", "LocalSuppress"}) TextView text = layout.findViewById(R.id.toast_text);
        text.setText(bankNames[position] + "\nIFSC Code: " + ifscCodes[position]);

        Toast toast = new Toast(getApplicationContext());
        toast.setDuration(Toast.LENGTH_LONG);
        toast.setView(layout);
        toast.show();
    }
}

using System;
//PROPERTY OF GROUP 5 BSIT - 1I QCU 
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
//PROPERTY OF GROUP 5 BSIT - 1I QCU 
namespace FinalArduino
{
    public partial class Form1 : Form
    {
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        public Form1()
        {
            InitializeComponent();

            serialPort1.DataReceived += SerialPort1_DataReceived;
            serialPort1.Open();
        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Earthquake Drill Simulated Succesffully!");
            serialPort1.Write("DRILL_ON");
            button2.BackColor = System.Drawing.Color.Green;
        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Write("DRILL_OFF");
            button1.BackColor = System.Drawing.Color.Green;

        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void button4_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Earthquake Detected! Please Evacuate");
            serialPort1.Write("DISASTER_ON");
            button4.BackColor = System.Drawing.Color.Green;

        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void button3_Click(object sender, EventArgs e)
        {
            serialPort1.Write("DISASTER_OFF");
            button3.BackColor = System.Drawing.Color.Green;
        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void panel13_Paint(object sender, PaintEventArgs e)
        {

        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void panel11_Paint(object sender, PaintEventArgs e)
        {
            //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void panel10_Paint(object sender, PaintEventArgs e)
        {

        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void label13_Click(object sender, EventArgs e)
        {

        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void label15_Click(object sender, EventArgs e)
        {

        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void panel15_Paint(object sender, PaintEventArgs e)
        {
        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void button5_Click(object sender, EventArgs e)
        {
            //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        }
        private void SerialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            string data = serialPort1.ReadLine();
            this.BeginInvoke(new Action(() =>
            {
                outputdata.Clear();
                outputdata.Text += data + Environment.NewLine;
            }));
        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void label27_Click(object sender, EventArgs e)
        {

        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void button5_Click_1(object sender, EventArgs e)
        {
            MessageBox.Show("All Lights Turned On Succesfully.");
            serialPort1.Write("MAIN_ON");
            button5.BackColor = System.Drawing.Color.Green;

        }

        private void button8_Click(object sender, EventArgs e)
        {
            MessageBox.Show("First Floor Lights Activated Succesfully.");
            serialPort1.Write("F1_ON");
            button8.BackColor = System.Drawing.Color.Green;

        }

        private void button10_Click(object sender, EventArgs e)
        {
            serialPort1.Write("F2_ON");
            MessageBox.Show("Second Floor Lights Activated Succesfully.");
            button10.BackColor = System.Drawing.Color.Green;

        }

        private void button9_Click(object sender, EventArgs e)
        {
            serialPort1.Write("F2_OFF");
            MessageBox.Show("Second Floor Lights Deactivated Succesfully.");
            button9.BackColor = System.Drawing.Color.Green;

        }

        private void button6_Click(object sender, EventArgs e)
        {
            MessageBox.Show("First Floor Lights Deactivated Succesfully.");
            serialPort1.Write("F1_OFF");
            button6.BackColor = System.Drawing.Color.Green;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            MessageBox.Show("All Lights Turned Off Succesfully.");
            serialPort1.Write("MAIN_OFF");
            button7.BackColor = System.Drawing.Color.Green;
        }

        private void button12_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Gate Opened Succesfully.");
            serialPort1.Write("SERVO_OPEN");
            button12.BackColor = System.Drawing.Color.Green;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Gate Closed Succesfully.");
            serialPort1.Write("SERVO_CLOSE");
            button11.BackColor = System.Drawing.Color.Green;

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {
            //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        }

        private void label12_Click(object sender, EventArgs e)
        {

        }

        private void panel27_Paint(object sender, PaintEventArgs e)
        { //PROPERTY OF GROUP 5 BSIT - 1I QCU 

        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {

        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        }

        private void comboBox_portLists_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void button_open_Click(object sender, EventArgs e)
        {

        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void Form1_Load(object sender, EventArgs e)
        {
            //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void button13_Click(object sender, EventArgs e)
        {
            buttonSetAlarm_Click.BackColor = System.Drawing.Color.Green;
            MessageBox.Show("Alarm Set Succesfully!");
            DateTime alarmTime = dateTimePicker1.Value;
            Timer timer = new Timer();
            timer.Interval = 1000; // Check every second
            timer.Tick += (s, args) =>
            {
                if (DateTime.Now >= alarmTime)
                {
                    timer.Stop();
                    ActivateAlarm();
                }
            };
            timer.Start();
        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void ActivateAlarm()
        {
            // Send the "ALARM" string to the Arduino
            serialPort1.WriteLine("ALARM");
        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void button13_Click_1(object sender, EventArgs e)
        {
            DateTime alarmTime = dateTimePicker1.Value;
            Timer timer = new Timer();
            timer.Interval = 1000; // Check every second
            timer.Tick += (s, args) =>
            {
                if (DateTime.Now >= alarmTime)
                {
                    timer.Stop();
                    ActivateAlarm();
                }
            };
            timer.Start();
        }
        //PROPERTY OF GROUP 5 BSIT - 1I QCU 
        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }
    }
} //PROPERTY OF GROUP 5 BSIT - 1I QCU 

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EmbedSysProjVer1{
    public partial class Form1 : Form{
        string serialDataIn;
        sbyte indexOfHumid, indexOfTemp; indexOfDoor, indexOfPhsens, indexOfPlug;
        string dataSensorHumid, dataSensorTemp, dataDoor, dataSensorPh, dataPlug;
        public Form1()
        {
            InitializeComponent();
        }
        private void form1(object sender, EventArgs e)
        {
            button_open.Enabled = true;
            button_close.Enabled = false;
            comboBox_BaudRate.Text = "115200";
        }
        private void button_open_Click(object sender, EventArgs e)
        {
            try{
                serialPort1.PortName = comboBox_ComPort.Text;
                serialPort1.BaudRate = Convert.ToInt32(comboBox_BaudRate.Text);
                serialPort1.Open();

                button_open.Enabled = false;
                button_close.Enabled = true;
            }
            catch(Exception error){
                MessageBox.Show(error.Message);
            }
        }
        private void comboBox_ComPort_DropDown(object sender, EventArgs e)
        {
            string[] portList = Serialport.GetPortNames();
            comboBox_ComPort.Items.Clear();
            comboBox_ComPort.Items.AddRange(portList);
        }
        private void button_doorOpen_Click(object sender, EventArgs e)
        {
            serialPort1.Write("Q");
        }
        private void button_doorClose_Click(object sender, EventArgs e)
        {
            serialPort1.Write("W");
        }
        private void button_ledRed_Click(object sender, EventArgs e)
        {
            serialPort1.Write("E");
        }
        private void button_ledGreed_Click(object sender, EventArgs e)
        {
            serialPort1.Write("R");
        }
        private void button_ledBlue_Click(object sender, EventArgs e)
        {
            serialPort1.Write("T");
        }
        private void button_ledOff_Click(object sender, EventArgs e)
        {
            serialPort1.Write("Y");
        }
        private void button_plugOn_Click(object sender, EventArgs e)
        {
            serialPort1.Write("U");
        }
        private void button_plugOff_Click(object sender, EventArgs e)
        {
            serialPort1.Write("I");
        }
        private void button_close_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.Close();
                button_open.Enabled() = true;
                button_close.Enabled() = false;
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }
        private void comboBox_ComPort_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
        private void comboBox_ComPort_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                serialPort1.Close();
            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }
        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            serialDataIn = serialPort1.ReadLine();
            this.BeginInvoke(new EventHandler(ProcessData));
        }
        private void ProcessData(object sender, EventArgs e)
        {
            try
            {
                indexOfHumid = Convert.ToSByte(serialDataIn.IndexOf("A"));
                indexOfTemp = Convert.ToSByte(serialDataIn.IndexOf("B"));
                indexOfDoor = Convert.ToSByte(serialDataIn.IndexOf("C"));
                indexOfPhsens = Convert.ToSByte(serialDataIn.IndexOf("D"));
                indexOfPlug = Convert.ToSByte(serialDataIn.IndexOf("F"));

                dataSensorHumid = serialDataIn.Substring(0, indexOfHumid);
                dataSensorTemp = serialDataIn.Substring(indexOfHumid + 1, (indexOfTemp - indexOfHumid) - 1);
                dataDoor = serialDataIn.Substring(indexOfTemp + 1, (indexOfDoor - indexOfTemp) - 1);
                dataSensorPh = serialDataIn.Substring(indexOfDoor + 1, (indexOfPhsens - indexOfDoor) - 1);
                dataPlug = serialDataIn.Substring(indexOfPhsens + 1, (indexOfPlug - indexOfPhsens) - 1);

                textBox_humidity.Text = dataSensorHumid;
                textBox_temperature.Text = dataSensorTemp;
                textBox_doorState.Text = dataDoor;
                textBox_photosensor.Text = dataSensorPh;
                textBox_plug.Text = dataPlug;
            }
            catch(Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }
    }
}
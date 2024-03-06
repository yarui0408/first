using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BookSopTotu
{
    public partial class AdminLogin : Form
    {
        public AdminLogin()
        {
            InitializeComponent();
        }

        private void label7_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void buttonlogin_Click(object sender, EventArgs e)
        {
            if(boxPassword.Text=="password")
            {
                books obj = new books();
                obj.Show();
                this.Hide();
            }
            else
            {
                MessageBox.Show("密码错误！！！");
            }
        }

        private void label3_Click(object sender, EventArgs e)
        {
            Login obj = new Login();
            obj.Show();
            this.Hide();
        }
    }
}

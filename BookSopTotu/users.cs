using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BookSopTotu
{
    public partial class users : Form
    {
        public users()
        {
            InitializeComponent();
            populate();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void dgvUser_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            boxName.Text = dgvUser.SelectedRows[0].Cells[1].Value.ToString();
            boxAddress.Text = dgvUser.SelectedRows[0].Cells[3].Value.ToString();

            boxPassword.Text = dgvUser.SelectedRows[0].Cells[4].Value.ToString();
            boxPhone.Text = dgvUser.SelectedRows[0].Cells[2].Value.ToString();
           
            if (boxName.Text == "")
            {
                key = 0;
            }
            else
            {
                key = Convert.ToInt32(dgvUser.SelectedRows[0].Cells[0].Value.ToString());
            }
        }


        int key = 0;
        SqlConnection Con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\benye\Documents\bookShopDB.mdf;Integrated Security=True;Connect Timeout=30;Encrypt=False");
        private void Reset()
        {
            boxName.Text = " ";
            boxAddress.Text = " ";
            
            boxPassword.Text = " ";
            boxPhone.Text = " ";

        }

        private void populate()
        {
            Con.Open();
            string query = "select *from UserTbl";
            SqlDataAdapter adapter = new SqlDataAdapter(query, Con);
            SqlCommandBuilder sqlCommandBuilder = new SqlCommandBuilder(adapter);
            var dataset = new DataSet();
            adapter.Fill(dataset);
            dgvUser.DataSource = dataset.Tables[0];

            Con.Close();
        }
        private void buttonSave_Click(object sender, EventArgs e)
        {
            if (boxName.Text == "" || boxPhone.Text =="" || boxAddress.Text==""|| boxPassword.Text == "")
            {
                MessageBox.Show("信息缺失！！！");
            }
            else
            {
                try
                {
                    Con.Open();
                    string query = "insert into UserTbl values('" + boxName.Text + "','" + boxPhone.Text + "','"+ boxAddress.Text + "','" + boxPassword.Text + "')";
                    SqlCommand cmd = new SqlCommand(query, Con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("用户信息保存成功！！！");
                    Con.Close();
                    populate();
                    Reset();
                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                }
            }
        }

        private void label7_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void buttonEdit_Click(object sender, EventArgs e)
        {
            if (boxName.Text == "" || boxPhone.Text == "" || boxAddress.Text == "" || boxPassword.Text == "")
            {
                MessageBox.Show("信息缺失！！！");
            }
            else
            {
                try
                {
                    Con.Open();
                    string query = "update UserTbl set UName='" + boxName.Text + "',UPhone='" + boxPhone.Text + "',UAdd='" + boxAddress.Text + "',UPassword='" +boxPassword.Text + "' where UId=" + key + "";
                    SqlCommand cmd = new SqlCommand(query, Con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("用户信息更新成功！！！");
                    Con.Close();
                    populate();
                    Reset();
                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                }
            }
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if (key == 0)
            {
                MessageBox.Show("信息缺失！！！");
            }
            else
            {
                try
                {
                    Con.Open();
                    string query = "delete from UserTbl where UId=" + key + " ";
                    SqlCommand cmd = new SqlCommand(query, Con);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("用户信息删除成功！！！");
                    Con.Close();
                    populate();
                    Reset();
                }
                catch (Exception Ex)
                {
                    MessageBox.Show(Ex.Message);
                }
            }
        }

        private void buttonReset_Click(object sender, EventArgs e)
        {
            
                Reset();

           
        }

        private void label5_Click(object sender, EventArgs e)
        {
            books obj = new books();
            obj.Show();
            this.Hide();
        }

        private void label6_Click(object sender, EventArgs e)
        {
            users obj = new users();
            obj.Show();
            this.Hide();
        }

        private void label8_Click(object sender, EventArgs e)
        {
            manage obj = new manage();
            obj.Show();
            this.Hide();
        }

        private void panel3_Paint(object sender, PaintEventArgs e)
        {

        }

        private void users_Load(object sender, EventArgs e)
        {
           
        }
    }
}

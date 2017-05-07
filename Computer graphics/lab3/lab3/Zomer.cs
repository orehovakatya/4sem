using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace lab3
{
    /*class Zomer
    {
        private Rectangle prev;
        private PictureBox pb;
        private Bitmap bmt;
        private float Scale_factor = 1f;

        public Zomer(ref PictureBox pb, ref Bitmap bmt)
        {
            this.pb = pb;
            this.bmt = bmt;
            prev.Size = pb.Size;
            prev.Location = new Point(0, 0);
        }

        public float Scale
        {
            set
            {
                Scale_factor = value;
            }
        }

        public void zoom()
        {
            

            Size newSize = new Size((int)(bmt.Width * Scale_factor), (int)(bmt.Height * Scale_factor));
            Bitmap bmp = ResizeImage((Image)(bmt), newSize.Width, newSize.Height);
            Bitmap bmp2 = bmp.Clone(prev, bmp.PixelFormat);

            bmp.Dispose();

            pb.Image = bmp2;
        }

        private Bitmap ResizeImage(Image image, int width, int height)
        {
            var destRect = new Rectangle(0, 0, width, height);
            var destImage = new Bitmap(width, height);

            destImage.SetResolution(image.HorizontalResolution, image.VerticalResolution);

            using (var graphics = Graphics.FromImage(destImage))
            {
                graphics.CompositingMode = CompositingMode.SourceCopy;
                graphics.CompositingQuality = CompositingQuality.HighQuality;
                graphics.InterpolationMode = InterpolationMode.NearestNeighbor;
                graphics.SmoothingMode = SmoothingMode.None;
                graphics.PixelOffsetMode = PixelOffsetMode.HighQuality;

                graphics.DrawImage(image, destRect, 0, 0, image.Width, image.Height, GraphicsUnit.Pixel);

            }

            return destImage;
        }
    }*/

    class BitmapZoomer
    {
        private Rectangle prev;
        private int Xdelta;
        private int Ydelta;
        private float zoomFactor = 1f;

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Size">Default bitmap size</param>
        /// <param name="x_delta">Number pixel for offset by X</param>
        /// <param name="y_delta">Number pixel for offset by Y</param>
        public BitmapZoomer(Size Size, int x_delta, int y_delta)
        {
            prev.Size = Size;
            prev.Location = new Point(0, 0);
            Xdelta = x_delta;
            Ydelta = y_delta;

        }

        private Bitmap ResizeImage(Image image, int width, int height)
        {
            var destRect = new Rectangle(0, 0, width, height);
            var destImage = new Bitmap(width, height);

            destImage.SetResolution(image.HorizontalResolution, image.VerticalResolution);

            using (var graphics = Graphics.FromImage(destImage))
            {
                graphics.CompositingMode = CompositingMode.SourceCopy;
                graphics.CompositingQuality = CompositingQuality.HighQuality;
                graphics.InterpolationMode = InterpolationMode.NearestNeighbor;
                graphics.SmoothingMode = SmoothingMode.None;
                graphics.PixelOffsetMode = PixelOffsetMode.HighQuality;

                graphics.DrawImage(image, destRect, 0, 0, image.Width, image.Height, GraphicsUnit.Pixel);

            }

            return destImage;
        }

        public Bitmap zoom(ref Bitmap bitmap)
        {
            try
            {
                if (zoomFactor == 1f)
                {
                    prev.Location = new Point(0, 0);
                }

                Size newSize = new Size((int)(bitmap.Width * zoomFactor), (int)(bitmap.Height * zoomFactor));
                Bitmap bmp = ResizeImage((Image)(bitmap), newSize.Width, newSize.Height);
                Bitmap bmp2 = bmp.Clone(prev, bmp.PixelFormat);
                bmp.Dispose();
                //bmp2.Dispose();
                return bmp2;
            }
            catch { };

            return null;
        }

        public void setZoomFactor(string line)
        {
            zoomFactor = 1f;
            if (line == "")
                zoomFactor = 1f;
            else
            {
                try
                {
                    zoomFactor = 1f * Convert.ToInt32(line);
                }
                catch
                {
                }
            }
        }


        //Left
        public Bitmap Left(ref Bitmap bitmap)
        {
            if (prev.Location.X > 100)
                prev.Location = new Point(prev.Location.X - 100, prev.Location.Y);
            else
                prev.Location = new Point(0, prev.Location.Y);
            return zoom(ref bitmap);
        }

        //Up
        public Bitmap Up(ref Bitmap bitmap)
        {
            if (prev.Location.Y > 100)
                prev.Location = new Point(prev.Location.X, prev.Location.Y - 100);
            else
                prev.Location = new Point(prev.Location.X, 0);
            return zoom(ref bitmap);
        }

        //Right
        public Bitmap Right(ref Bitmap bitmap)
        {
            prev.Location = new Point(prev.Location.X + 100, prev.Location.Y);
            return zoom(ref bitmap);
        }

        //Down
        public Bitmap Down(ref Bitmap bitmap)
        {
            prev.Location = new Point(prev.Location.X, prev.Location.Y + 100);

            return zoom(ref bitmap);
        }
    }
}

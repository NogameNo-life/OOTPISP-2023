using System;

namespace Patterns
{
    class Eyes
    {
        public string Color { get; set; }
        public string Figure { get; set; }

        public Eyes(string color, string figure)
        {
            Color = color;
            Figure = figure;
        }
    }

    class Nose
    {
        public string Color { get; set; }
        public string Figure { get; set; }

        public Nose(string color, string figure)
        {
            Color = color;
            Figure = figure;
        }
    }

    class Mouth
    {
        public string Color { get; set; }
        public string Figure { get; set; }

        public Mouth(string color, string figure)
        {
            Color = color;
            Figure = figure;
        }
    }

    class Ears
    {
        public string Color { get; set; }
        public string Figure { get; set; }

        public Ears(string color, string figure)
        {
            Color = color;
            Figure = figure;
        }
    }

    class Hair
    {
        public string Color { get; set; }
        public string Figure { get; set; }

        public Hair(string color, string figure)
        {
            Color = color;
            Figure = figure;
        }
    }
    abstract class FaceBuilder
    {
        protected Eyes eyes;
        protected Nose nose;
        protected Mouth mouth;
        protected Ears ears;
        protected Hair hair;

        public void BuildEyes(string color, string figure)
        {
            eyes = new Eyes(color, figure);
        }

        public void BuildNose(string color, string figure)
        {
            nose = new Nose(color, figure);
        }

        public void BuildMouth(string color, string figure)
        {
            mouth = new Mouth(color, figure);
        }

        public void BuildEars(string color, string figure)
        {
            ears = new Ears(color, figure);
        }

        public void BuildHair(string color, string figure)
        {
            hair = new Hair(color, figure);
        }

        public abstract void DisplayFace();
    }
    class UglyFaceBuilder : FaceBuilder
    {
        public override void DisplayFace()
        {
            Console.WriteLine("Ugly face:");
            Console.WriteLine($"Eyes: Color - {eyes.Color}, Figure - {eyes.Figure}");
            Console.WriteLine($"Nose: Color - {nose.Color}, Figure - {nose.Figure}");
            Console.WriteLine($"Mouth: Color - {mouth.Color}, Figure - {mouth.Figure}");
            Console.WriteLine($"Ears: Color - {ears.Color}, Figure - {ears.Figure}");
            Console.WriteLine($"Hair: Color - {hair.Color}, Figure - {hair.Figure}");
        }
    }

   
    class GoodFaceBuilder : FaceBuilder
    {
        public override void DisplayFace()
        {
            Console.WriteLine("Good face:");
            Console.WriteLine($"Eyes: Color - {eyes.Color}, Figure - {eyes.Figure}");
            Console.WriteLine($"Nose: Color - {nose.Color}, Figure - {nose.Figure}");
            Console.WriteLine($"Mouth: Color - {mouth.Color}, Figure - {mouth.Figure}");
            Console.WriteLine($"Ears: Color - {ears.Color}, Figure - {ears.Figure}");
            Console.WriteLine($"Hair: Color - {hair.Color}, Figure - {hair.Figure}");
        }
    }
    class SmileFaceBuilder : FaceBuilder
    {
        public override void DisplayFace()
        {
            Console.WriteLine("Smile face:");
            Console.WriteLine($"Eyes: Color - {eyes.Color}, Figure - {eyes.Figure}");
            Console.WriteLine($"Nose: Color - {nose.Color}, Figure - {nose.Figure}");
            Console.WriteLine($"Mouth: Color - {mouth.Color}, Figure - {mouth.Figure} (with smile)");
            Console.WriteLine($"Ears: Color - {ears.Color}, Figure - {ears.Figure}");
            Console.WriteLine($"Hair: Color - {hair.Color}, Figure - {hair.Figure}");
        }
    }
    
    class Hero
    {
        private FaceBuilder faceBuilder;

        public void SetFaceBuilder(FaceBuilder builder)
        {
            faceBuilder = builder;
        }

        public void BuildFace()
        {
            faceBuilder.BuildEyes("Blue", "Round");
            faceBuilder.BuildNose("White", "Pointed");
            faceBuilder.BuildMouth("Red", "Small");
            faceBuilder.BuildEars("White", "Normal");
            faceBuilder.BuildHair("Black", "Short");
        }

        public void DisplayFace()
        {
            faceBuilder.DisplayFace();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Hero hero = new Hero();

            FaceBuilder uglyFaceBuilder = new UglyFaceBuilder();
            hero.SetFaceBuilder(uglyFaceBuilder);
            hero.BuildFace();
            hero.DisplayFace();

            Console.WriteLine();

            FaceBuilder goodFaceBuilder = new GoodFaceBuilder();
            hero.SetFaceBuilder(goodFaceBuilder);
            hero.BuildFace();
            hero.DisplayFace();

            Console.WriteLine();

            FaceBuilder smileFaceBuilder = new SmileFaceBuilder();
            hero.SetFaceBuilder(smileFaceBuilder);
            hero.BuildFace();
            hero.DisplayFace();

            Console.ReadLine();
        }
    }
}
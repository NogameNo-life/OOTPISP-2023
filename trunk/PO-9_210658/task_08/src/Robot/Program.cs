using System;

namespace Patterns
{
    class Head
    {
        public string Description { get; set; }
    }
    class Body
    {
        public string Description { get; set; }
    }
    class Engine
    {
        public string Description { get; set; }
    }
    interface IRobotBuilder
    {
        void BuildHead();
        void BuildBody();
        void BuildEngine();
        Robot GetRobot();
    }
    class RobotBuilder : IRobotBuilder
    {
        private Robot _robot;

        public RobotBuilder()
        {
            _robot = new Robot();
        }

        public void BuildHead()
        {
            _robot.Head = new Head { Description = "Standard Head" };
        }

        public void BuildBody()
        {
            _robot.Body = new Body { Description = "Standard Body" };
        }

        public void BuildEngine()
        {
            _robot.Engine = new Engine { Description = "Standard Engine" };
        }

        public Robot GetRobot()
        {
            return _robot;
        }
    }
    class Robot
    {
        public Head Head { get; set; }
        public Body Body { get; set; }
        public Engine Engine { get; set; }

        public void Display()
        {
            Console.WriteLine("Robot parts:");
            Console.WriteLine($"Head: {Head.Description}");
            Console.WriteLine($"Body: {Body.Description}");
            Console.WriteLine($"Engine: {Engine.Description}");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            IRobotBuilder robotBuilder = new RobotBuilder();
            robotBuilder.BuildHead();
            robotBuilder.BuildBody();
            robotBuilder.BuildEngine();

            Robot robot = robotBuilder.GetRobot();

            robot.Display();
        }
    }
}
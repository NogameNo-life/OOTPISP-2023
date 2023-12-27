using System;

namespace Patterns
{
    interface IReportBuilder
    {
        void BuildHeader(string header);
        void BuildBlock(string block);
        void BuildEnding(string ending);
        string GetReport();
    }
    class Report
    {
        private string _report;

        public void SetReport(string report)
        {
            _report = report;
        }

        public string GetReport()
        {
            return _report;
        }
    }

    class HtmlBuilder : IReportBuilder
    {
        private Report _report = new Report();

        public void BuildHeader(string header)
        {
            _report.SetReport($"<h1>{header}</h1>");
        }

        public void BuildBlock(string block)
        {
            _report.SetReport($"{_report.GetReport()}<p>{block}</p>");
        }

        public void BuildEnding(string ending)
        {
            _report.SetReport($"{_report.GetReport()}<p>{ending}</p>");
        }

        public string GetReport()
        {
            return _report.GetReport();
        }
    }

    class TxtBuilder : IReportBuilder
    {
        private Report _report = new Report();

        public void BuildHeader(string header)
        {
            _report.SetReport($"--- {header} ---");
        }

        public void BuildBlock(string block)
        {
            _report.SetReport($"{_report.GetReport()}\n{block}");
        }

        public void BuildEnding(string ending)
        {
            _report.SetReport($"{_report.GetReport()}\n{ending}");
        }

        public string GetReport()
        {
            return _report.GetReport();
        }
    }

    class XlsBuilder : IReportBuilder
    {
        private Report _report = new Report();

        public void BuildHeader(string header)
        {
            _report.SetReport($"[HEADER]\n{header}");
        }

        public void BuildBlock(string block)
        {
            _report.SetReport($"{_report.GetReport()}\n[BLOCK]\n{block}");
        }

        public void BuildEnding(string ending)
        {
            _report.SetReport($"{_report.GetReport()}\n[ENDING]\n{ending}");
        }

        public string GetReport()
        {
            return _report.GetReport();
        }
    }

    class DocBuilder : IReportBuilder
    {
        private Report _report = new Report();

        public void BuildHeader(string header)
        {
            _report.SetReport($"[Header] {header}");
        }

        public void BuildBlock(string block)
        {
            _report.SetReport($"{_report.GetReport()}\n[Block] {block}");
        }

        public void BuildEnding(string ending)
        {
            _report.SetReport($"{_report.GetReport()}\n[Ending] {ending}");
        }

        public string GetReport()
        {
            return _report.GetReport();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            IReportBuilder htmlBuilder = new HtmlBuilder();
            htmlBuilder.BuildHeader("Report Header");
            htmlBuilder.BuildBlock("Block 1");
            htmlBuilder.BuildBlock("Block 2");
            htmlBuilder.BuildEnding("Report Ending");
            string htmlReport = htmlBuilder.GetReport();
            Console.WriteLine("HTML Report:");
            Console.WriteLine(htmlReport);
            Console.WriteLine();

            IReportBuilder txtBuilder = new TxtBuilder();
            txtBuilder.BuildHeader("Report Header");
            txtBuilder.BuildBlock("Block 1");
            txtBuilder.BuildBlock("Block 2");
            txtBuilder.BuildEnding("Report Ending");
            string txtReport = txtBuilder.GetReport();
            Console.WriteLine("TXT Report:");
            Console.WriteLine(txtReport);
            Console.WriteLine();

            IReportBuilder xlsBuilder = new XlsBuilder();
            xlsBuilder.BuildHeader("Report Header");
            xlsBuilder.BuildBlock("Block 1");
            xlsBuilder.BuildBlock("Block 2");
            xlsBuilder.BuildEnding("Report Ending");
            string xlsReport = xlsBuilder.GetReport();
            Console.WriteLine("DOC Report:");
            Console.WriteLine(xlsReport);
            Console.WriteLine();
        }
    }
}
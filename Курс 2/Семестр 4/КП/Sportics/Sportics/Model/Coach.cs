﻿

using System.Collections.Generic;

namespace Sportics.Model
{
    public class Coach
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string PhoneNumber { get; set; }
        public string Specialization { get; set; }
        public string Information { get; set; }
        public byte[] Photo { get; set; }

        public List<Schedule> Schedules { get; set; }
    }
}

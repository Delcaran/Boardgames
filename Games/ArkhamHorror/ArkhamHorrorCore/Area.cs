using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArkhamHorrorCore
{
    abstract class Area
    {
        private readonly string _name;
        private List<Area> _linkedTo;
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sportics.Model
{
    public interface IUnitOfWork : IDisposable
    {
        IMembershipRepository Memberships { get; }
        IMembershipOrderRepository MembershipOrders { get; }
        void Commit();
    }

}

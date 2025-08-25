using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sportics.Model
{
    public class UnitOfWork : IUnitOfWork
    {
        public IMembershipRepository Memberships { get; }
        public IMembershipOrderRepository MembershipOrders { get; }

        public UnitOfWork()
        {
            Memberships = new MembershipRepositoryWrapper();
            MembershipOrders = new MembershipOrderRepositoryWrapper();
        }

        public void Commit() { }

        public void Dispose() { }
    }

}

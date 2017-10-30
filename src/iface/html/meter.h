#ifndef GBD88D245_DBDE_4EC1_A670_0EF9B70AB8A0
#define GBD88D245_DBDE_4EC1_A670_0EF9B70AB8A0


#include <html/details/symetric_tag_with_attributes.h>


namespace html
{
class Meter final : public details::SymetricTagWithAttributes
{
public:
	//! [min        low        high       max]
	//!///////////////////////////////////////
	//!    >optimum<
	//! [    green   |  yellow  |     red    ]
	//!///////////////////////////////////////
	//!                >optimum<
	//! [   yellow   |   green  |   yellow   ]
	//!///////////////////////////////////////
	//!                            >optimum<
	//! [     red    |  yellow  |    green   ]
	//!///////////////////////////////////////
	explicit Meter(double min, double low, double high, double max, double optimum, double value);
};
}


#endif//GBD88D245_DBDE_4EC1_A670_0EF9B70AB8A0

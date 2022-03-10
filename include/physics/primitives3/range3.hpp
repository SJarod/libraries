#pragma once

namespace Physics
{
	namespace Primitives3
	{
		class Range3
		{
		public:
			float min;
			float max;

			Range3() = default;
			Range3(const float& min, const float& max);

			float length() const;
		};
	}
}

using namespace Physics;
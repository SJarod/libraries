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

			/**
			 * Create a range.
			 * 
			 * @param min
			 * @param max
			 */
			Range3(const float& min, const float& max);

			/**
			 * Length of the range.
			 * 
			 * @return 
			 */
			float length() const;
		};
	}
}
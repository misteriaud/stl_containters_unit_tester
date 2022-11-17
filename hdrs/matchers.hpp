#include "common.hpp"

namespace Custom
{
//
// MATCHER
//
	template<typename VectorType>
	class VectorEqual : public Catch::MatcherBase<VectorType> {
	public:
		typedef typename VectorType::value_type		ValueType;
		typedef typename VectorType::allocator_type	AllocComp;


		VectorEqual(std::vector<ValueType, AllocComp> const &comparator) : m_comparator( comparator ) {}

		bool match(VectorType const &v) const {
			if (m_comparator.size() != v.size())
				return false;
			for (std::size_t i = 0; i < v.size(); ++i)
				if (m_comparator[i] != v[i])
					return false;
			return true;
		}
		std::string describe() const {
			std::ostringstream ss;
			ss << "\nEquality between ft::vector && std::vector: \n";

			// IF YOU GET A COMPILATION ERROR HERE, NEED TO IMPLEMENT : `std::ostream& operator<< (std::ostream& out, const YourType& rhs)`
			ss << Catch::StringMaker<std::vector<ValueType> >::convert(m_comparator);
			return ss.str();
		}
		std::vector<ValueType, AllocComp> const& m_comparator;
	};


	template<typename MapType>
	class MapEqual : public Catch::MatcherBase<MapType> {
	public:
		typedef typename MapType::key_type			key_type;
		typedef typename MapType::mapped_type		mapped_type;
		typedef typename MapType::key_compare		key_compare;
		typedef typename MapType::allocator_type	allocator_type;
		typedef typename MapType::const_iterator	ConstIt;

		typedef std::map<key_type, mapped_type, key_compare, allocator_type>	std_map_type;
		typedef typename std_map_type::const_iterator	StdConstIt;


		// MapEqual(std_map_type const& comparator) : std_map(&comparator), ft_map(NULL) {}
		MapEqual(Map const& comparator) : ft_map(comparator) {}

		bool match(MapType const &v) const {
			ConstIt mapFirst = v.begin(), mapLast = v.end();
			ConstIt refFirst = ft_map.begin(), refLast = ft_map.end();

			while (mapFirst!=mapLast && refFirst!=refLast) {
				if (*mapFirst != *refFirst)
					return false;
				++mapFirst; ++refFirst;
			}
			if (mapFirst == mapLast && refFirst == refLast)
				return true;
			return false;
		}
		std::string describe() const {
			std::ostringstream ss;
			ss << "\nEquality two maps: \n";

			// IF YOU GET A COMPILATION ERROR HERE, NEED TO IMPLEMENT : `std::ostream& operator<< (std::ostream& out, const YourType& rhs)`
			ss << Catch::StringMaker<Map>::convert(ft_map);
			return ss.str();
		}
		// std_map_type const	*std_map;
		Map const&			ft_map;
	};

}
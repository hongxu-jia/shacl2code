/**
 * @file
 *
 * Generated C++ bindings from a SHACL model
 *
 * This file was automatically generated by shacl2code. DO NOT MANUALLY MODIFY IT
 *
 * SPDX-License-Identifier: MIT
 */

/* */
#ifndef _SHACL2CODE_TEST_DATETIME_HPP
#define _SHACL2CODE_TEST_DATETIME_HPP

/* */

#include <optional>
#include <ostream>
#include <regex>
#include <string>

/* */
#ifndef DOXYGEN_SKIP
#include "api.hpp"
// These are so that we don't have to use Jinja templates below since that messes up the formatting
#define EXPORT SHACL2CODE_TEST_API
#define LOCAL  SHACL2CODE_TEST_LOCAL
#endif // DOXYGEN_SKIP

/* */
/* */
namespace test {
/* */

/**
 * @brief Date and Time Type
 *
 * Represents a point in time as the number of seconds that have elapsed
 * since Midnight on January 1st, 1970 and additionally a time zone offset.
 *
 * The Timezone offset may be negative for time zones West of UTC, and
 * positive for time zones East of UTC. If the time zone is split into hours
 * and minutes, the hour will have the sign while the minutes are always
 * positive
 */
class EXPORT DateTime {
   public:
    /**
     * @brief Constructor
     *
     * Constructs a new DateTime from the specified time stamp and timezone
     * offset
     */
    explicit DateTime(time_t time, int tzoffset = 0);

    /// Destructor
    virtual ~DateTime();

    /**
     * @brief Get timestamp
     *
     * @returns The time as the number of seconds that have elapsed since
     * Midnight on January 1st, 1970 in UTC
     */
    time_t time() const { return mTime; }

    /**
     * @brief Get DateTime as a string
     *
     * @returns a ISO 8601 formatted string representing the DateTime
     */
    std::string toString() const;

    /**
     * @brief Get timezone offset in seconds
     *
     * @returns The number of seconds by which the time zone offsets the
     * time. This will be positive for time zones East of UTC, and negative
     * for time zones West of UTC. The number is suitable for adding to a
     * timestamp since it correctly adds the hours and minutes based on the
     * sign
     */
    int tzOffsetSeconds() const;

    /**
     * @brief Parse string as a DateTime
     *
     * Parses a ISO 8601 formatted string as a DateTime.
     *
     * @note Not all ISO 8601 strings can be correctly parsed
     */
    static std::optional<DateTime> fromString(std::string const& s,
                                              bool tzRequired);

   private:
    /// Timestamp format String
    LOCAL static const char TimeFormat[];
    /// Time Zone format String
    LOCAL static const char TzFormat[];
    /// Regex Match string
    LOCAL static const std::regex MatchRegex;

    time_t mTime;
    int mTZoffset = 0;
};

/**
 * @brief Write DateTime to output stream
 *
 * Operator used to write out a DateTime to an output stream
 */
extern EXPORT std::ostream& operator<<(std::ostream& stream,
                                       DateTime const& datetime);

/* */
#undef EXPORT
#undef LOCAL

/* */
/* */
}
/* */
/* */
#endif // _SHACL2CODE_TEST_DATETIME_HPP
/* */

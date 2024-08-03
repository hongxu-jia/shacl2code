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
#ifndef _SHACL2CODE_TEST_CONTEXT_ERRORHANDLER_HPP
#define _SHACL2CODE_TEST_CONTEXT_ERRORHANDLER_HPP

/* */

#include <string>

/* */
#ifndef DOXYGEN_SKIP
#include "api.hpp"
// These are so that we don't have to use Jinja templates below since that messes up the formatting
#define EXPORT SHACL2CODE_TEST_CONTEXT_API
#define LOCAL  SHACL2CODE_TEST_CONTEXT_LOCAL
#endif // DOXYGEN_SKIP

/* */
/* */
namespace test_context {
/* */

class ObjectPath;

/**
 * @brief Error handler
 *
 * Abstract base class that defines the interface for an error handling
 * implementation
 */
class EXPORT ErrorHandler {
   public:
    /**
     * @brief Handle Validation Error
     *
     * If a property or object does not pass validation, this will be called to
     * report the error
     *
     * @param[in] message   The error message
     * @param[in] path      The ObjectPath of the item that caused the error
     */
    virtual void handleValidationError(std::string const& message,
                                       ObjectPath const& path) = 0;

    /**
     * @brief Handle Deserialize Error
     *
     * If an error is encountered while deserializing, this will be called to
     * report it
     *
     * @param[in] message   The error message
     * @param[in] path      The ObjectPath of the item that caused the error
     */
    virtual void handleDeserializeError(std::string const& message,
                                        ObjectPath const& path) = 0;
};

/**
 * @brief Default Error Handler
 *
 * The default handler for errors if no other handler is defined
 */
class EXPORT DefaultErrorHandler : public ErrorHandler {
   public:
    /// Constructor
    DefaultErrorHandler();

    /// Destructor
    virtual ~DefaultErrorHandler();

    DefaultErrorHandler(DefaultErrorHandler const&) = delete;
    DefaultErrorHandler(DefaultErrorHandler&&) = delete;
    DefaultErrorHandler& operator=(DefaultErrorHandler const&) = delete;
    DefaultErrorHandler& operator=(DefaultErrorHandler&&) = delete;

    /**
     * @copydoc ::test_context::ErrorHandler::handleValidationError
     *
     * @throws ValidationError to report the error
     */
    void handleValidationError(std::string const& message,
                               ObjectPath const& path) override;

    /**
     * @copydoc ::test_context::ErrorHandler::handleDeserializeError
     *
     * @throws DeserializeError to report the error
     */
    void handleDeserializeError(std::string const& message,
                                ObjectPath const& path) override;

    /**
     * @brief Default Handler
     *
     * The default handler that throws an exception on any errors
     */
    static DefaultErrorHandler handler;
};

/**
 * @brief Noop Error Handler
 *
 * An error handler that does nothing
 */
class EXPORT NoopErrorHandler : public ErrorHandler {
   public:
    /// Constructor
    NoopErrorHandler();

    /// Destructor
    virtual ~NoopErrorHandler();

    NoopErrorHandler(NoopErrorHandler const&) = delete;
    NoopErrorHandler(NoopErrorHandler&&) = delete;
    NoopErrorHandler& operator=(NoopErrorHandler const&) = delete;
    NoopErrorHandler& operator=(NoopErrorHandler&&) = delete;

    /**
     * @copydoc ::test_context::ErrorHandler::handleValidationError
     *
     * @throws ValidationError to report the error
     */
    void handleValidationError(std::string const& message,
                               ObjectPath const& path) override;

    /**
     * @copydoc ::test_context::ErrorHandler::handleDeserializeError
     *
     * @throws DeserializeError to report the error
     */
    void handleDeserializeError(std::string const& message,
                                ObjectPath const& path) override;

    /**
     * @brief Default Handler
     *
     * The default handler that throws an exception on any errors
     */
    static NoopErrorHandler handler;
};

/* */
#undef EXPORT
#undef LOCAL

/* */
/* */
}
/* */
/* */
#endif // _SHACL2CODE_TEST_CONTEXT_ERRORHANDLER_HPP
/* */

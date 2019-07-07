/**
 * @date 2019
 * First-pass visitor for converting Solidity ADT's into structs in C.
 */

#pragma once

#include <libsolidity/ast/ASTVisitor.h>
#include <libsolidity/modelcheck/TypeTranslator.h>
#include <list>
#include <ostream>
#include <string>

namespace dev
{
namespace solidity
{
namespace modelcheck
{

/**
 * Interprets the AST in terms of its C model, and prints forward declarations
 * for each of structures.
 */
class ADTForwardDeclVisitor : public ASTConstVisitor
{
public:
    // Constructs a printer for all forward decl's required by ast's c model.
    ADTForwardDeclVisitor(
        ASTNode const& _ast,
		TypeConverter const& _converter
    );

    // Prints each for declaration once, in some order.
    void print(std::ostream& _stream);

	bool visit(ContractDefinition const& _node) override;
	bool visit(Mapping const& _node) override;
	bool visit(StructDefinition const& _node) override;

	bool visit(EventDefinition const& _node) override;
	bool visit(FunctionDefinition const& _node) override;
	bool visit(ModifierDefinition const& _node) override;

private:
	ASTNode const* m_ast;
	TypeConverter const& m_converter;
	std::ostream* m_ostream = nullptr;
};

}
}
}

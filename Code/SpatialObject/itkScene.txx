/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkScene.txx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#ifndef __Scene_txx
#define __Scene_txx

#include "itkScene.h"
#include <algorithm>

namespace itk
{
  
/** Constructor */
template <unsigned int SpaceDimension>
Scene<SpaceDimension>
::Scene()
{
}

/** Destructor */
template <unsigned int SpaceDimension>
Scene<SpaceDimension>
::~Scene()
{
}

/** Add a spatial object to the scene */
template <unsigned int SpaceDimension>
void 
Scene<SpaceDimension>
::AddSpatialObject( NDimensionalSpatialObject<> * pointer )
{
  m_Objects.push_back( pointer );
  this->Modified();
}

/** Remove a spatial object from the scene */
template <unsigned int SpaceDimension>
void 
Scene<SpaceDimension>
::RemoveSpatialObject( NDimensionalSpatialObject<> * pointer )
{
  typename ObjectListType::iterator it;    
  it = std::find(m_Objects.begin(),m_Objects.end(),pointer);

  if( it != m_Objects.end() )
  {
    if( *it == pointer )
    {
      m_Objects.erase( it );
      this->Modified();
    }
  }
  else
  { 
    //throw an exception object to let user know that he tried to remove an object
    // which is not in the list of the children.
  }
}


/** Return the modification time of the scene */
template <unsigned int SpaceDimension>
unsigned long
Scene<SpaceDimension>
::GetMTime( void ) const
{
  typename ObjectListType::const_iterator it = m_Objects.begin();
  typename ObjectListType::const_iterator itEnd = m_Objects.end();
 
  unsigned long latestTime = Superclass::GetMTime();
  unsigned long localTime;
  while(it!=itEnd)
  {
    localTime = (*it)->GetMTime();
    if( localTime > latestTime )
    {
      latestTime = localTime;
    }
  it++;
  } 
  return latestTime;
}

/** Return the children list */
template <unsigned int SpaceDimension>
typename Scene<SpaceDimension>::ObjectListType *
Scene<SpaceDimension>
::GetObjects( unsigned int depth, char * name )
{
  ObjectListType * newList = new ObjectListType;

  typename ObjectListType::const_iterator it = m_Objects.begin();
  typename ObjectListType::const_iterator itEnd = m_Objects.end();

  while(it != itEnd)
    {
    if(name == NULL || strstr(typeid(**it).name(), name))
      {
      newList->push_back(*it);
      }
    if(depth>0)
      {
      typedef typename SpatialObject<SpaceDimension>::ChildrenListType
            ChildListType;
      ChildListType * childList = 
                     (dynamic_cast<SpatialObject<SpaceDimension> *>(*it))->
                     GetChildren(depth-1, name);
      typename ChildListType::const_iterator cIt = childList->begin();
      typename ChildListType::const_iterator cItEnd = childList->end();

      while(cIt != cItEnd)
        {
        newList->push_back(dynamic_cast< ObjectType * >(*cIt));
        cIt++;
        }

      delete childList;
      }
    it++;
    }

  return newList;
}

/** Set the children list */
template <unsigned int SpaceDimension>
void
Scene<SpaceDimension>
::SetObjects( ObjectListType & children )
{ 
  m_Objects = children;
}

/** Return the number of objects in the scene */
template <unsigned int SpaceDimension>
unsigned int
Scene<SpaceDimension>
::GetNumberOfObjects( unsigned int depth, char * name )
{
  typename ObjectListType::const_iterator it = m_Objects.begin();
  typename ObjectListType::const_iterator itEnd = m_Objects.end();

  unsigned int cnt = 0;
  while(it != itEnd)
    {
    if(name == NULL || strstr(typeid(**it).name(), name))
      {
      cnt++;
      }
    it++;
    }

  it = m_Objects.begin();
  itEnd = m_Objects.end();
  if( depth > 0 )
    {
    while(it != itEnd)
      {
      cnt += (dynamic_cast<SpatialObject<SpaceDimension> * >(*it))->
              GetNumberOfChildren( depth-1, name );
      it++;
      }
    }

  return cnt;
} 

/** Print the object */
template <unsigned int SpaceDimension>
void
Scene<SpaceDimension>
::PrintSelf( std::ostream& os, Indent indent ) const
{
  os << indent << "Number of objects: " 
     << m_Objects.size() << std::endl;
  os << indent << "List of objects: ";

  typename ObjectListType::const_iterator it = m_Objects.begin();
  typename ObjectListType::const_iterator itEnd = m_Objects.end();

  while(it != itEnd)
  {
    os << "[" << (*it) << "] ";
    it++;
  }
  os << std::endl;

  Superclass::PrintSelf(os, indent);
}

/** Return a SpatialObject in the scene 
 *  given a parent ID */
template <unsigned int SpaceDimension>
NDimensionalSpatialObject<> *
Scene<SpaceDimension>
::GetObjectById(int Id)
{
  typename ObjectListType::iterator it = m_Objects.begin();
  typename ObjectListType::iterator itEnd = m_Objects.end();
    
  while( it != itEnd )
  {
    if( (*it)->GetId() == Id )
    { 
      return *it;
    }
    it++;
  }
  return NULL;
}


} // end of namespace itk 

#endif
